#include <iostream>
#include <cmath>
#include <string>
#include <vector>
#include <algorithm>
#define BIG 90000000
#define MAX_SPEED 100
#define SMALL 0.000001f
#define MIN_DISTANCE 2000
using namespace std;

struct Vector{
	float x;
	float y;
	Vector(void){
		this->x=0;
		this->y=0;
	}
	Vector(float x,float y){
		this->x=x;
		this->y=y;
	}
	void add(Vector another){
		this->x+=another.x;
		this->y+=another.y;
	}
	void subtract(Vector another){
		this->x-=another.x;
		this->y-=another.y;
	}
	void multiply(float scalar){
		this->x*=scalar;
		this->y*=scalar;
	}
	Vector plus(Vector another){
		return Vector(this->x+another.x,this->y+another.y);
	}
	Vector minus(Vector another){
		return Vector(this->x-another.x,this->y-another.y);
	}
	Vector times(float scalar){
		return Vector(scalar*this->x,scalar*this->y);
	}
	float norm(){
		float x2 = this->x*this->x;
		float y2 = this->y*this->y;
		return sqrt(x2+y2);
	}
	float norm2(){
		return this->norm()*this->norm();
	}
	float norm3(){
		return this->norm2()*this->norm();
	}
	Vector normalized(){
		float norm = this->norm();
		if(norm!=0.0f)
			return this->times(1/norm);
		else
			return Vector();
	}
	void normalize(){
		*this = this->normalized();
	}
	float scalarProd(Vector other){
		return this->x*other.x+this->y*other.y;
	}
	Vector complexProd(Vector other){
		return Vector(this->x*other.x-this->y*other.y,this->x*other.y+this->y*other.x);
	}
};
struct Object{
	Vector position;
	Vector velocity;
	float radius;
	int id;
	int player;
	bool isTowards(Object other){
		//parametric equation of self
		//this->position(t) = this->position(0)+this->velocity*t :: f1=s1+v1*t
		//other.position(t) = other.position(0)+other.velocity*t :: f2=s2+v2*t
		//
		//d = sqrt((f1.x-f2.x)^2+(f1.y-f2.y)^2) = sqrt(((xs1-xs2)+(vx1-vx2)t)^2+((ys1-ys2)+(vy1-vy2)t)^2)
		//vr = dd/dt = (1/d)(((xs1-xs2)+(vx1-vx2)t(vx1-vx2))+((ys1-ys2)+(vy1-vy2)t(vy1-vy2))) = (1/d)((dx+dvx)t*dv+y(dy+dvy)t*dvy)
		//vr=0 => (dx+dvx*t)*dvx+y(dy+dvy*t)*dvy=0 => dx*dvx+t*dvx²=dy*dvy+t*dvy²
		//t=(dvx²-dvy²)/(dy*dvy-dx*dvx)

		float dx = other.position.x-this->position.x;
		float dy = other.position.y-this->position.y;
		float dx2 = dx*dx;
		float dy2 = dy*dy;
		float dvx = other.velocity.x-this->velocity.x;
		float dvy = other.velocity.y-this->velocity.y;
		float dvx2 = dvx*dvx;
		float dvy2 = dvy*dvy;
		//Derivandom encontro esses valores
		float t = (dvx2-dvy2)/(dy*dvy-dx*dvx);

		//Aplicando na equação original
		float minDist = sqrt(dx2+dy2);

		return minDist<this->radius+other.radius;
	}
};
Vector meanPosition(vector<Object> list){
	Vector retVal = Vector();
	for(int t=0;t<list.size();t++)
		retVal.add(list[t].position.times(1.0f/list.size()));
	return retVal;
}

Object closest(Object self, vector<Object> list){
	float min = BIG;
	Object retVal;
	for (int t=0;t<list.size();t++){
		Object other=list[t];
		if(other.id!=self.id){
			Vector posDiff = other.position.minus(self.position);
			float dist = posDiff.norm()-self.radius-other.radius;
			if(dist<min){
				min=dist;
				retVal = other;
			}
		}
	}
	return retVal;
}
Object mostImportant(Object self, vector<Object> list){
	float max = 0;
	Object retVal;
	bool found=false;
	for (int t=0;t<list.size();t++){
		Object other=list[t];
		if(other.id!=self.id){
			Vector posDiff = other.position.minus(self.position);
			float dist = posDiff.norm()-self.radius-other.radius;
			float importance = other.radius/dist;
			if(importance>max && self.isTowards(other)){
				found=true;
				max=importance;
				retVal = other;
			}
		}
	}
	if(!found){
		return self;
	}
	return retVal;
}
Vector inteligence(Object self, vector<Object> list){
	Vector velocity=Vector();
	Object other = mostImportant(self,list);
	if(other.id==self.id)
		other = closest(self,list);
	if(other.id!=self.id){
		float radDiff = other.radius-self.radius;
		Vector posDiff = other.position.minus(self.position);
		float touchDist = posDiff.norm()-self.radius-other.radius;
		float touchDist2 = touchDist*touchDist;
		float touchDist3 = touchDist2*touchDist;
		Vector term = posDiff.times(radDiff/touchDist3);
		if(self.velocity.norm()>self.velocity.norm())
			term.subtract(self.velocity);
		if(other.player==self.player){
			if(!self.isTowards(other))
				velocity.add(term);
			cerr<<"friend "<<self.isTowards(other)<<endl;
		}else{
			if(self.isTowards(other))
				velocity.subtract(term);
			cerr<<"enemy "<<self.isTowards(other)<<endl;
		}
		//------------DEBUG-------------------------------
		cerr<<"radDiff: "<<radDiff<<endl;
		cerr<<"speed: "<<self.velocity.norm()<<endl;
		cerr<<"touchDist: "<<touchDist<<endl;
		cerr<<"posDiff: "<<posDiff.x<<" "<<posDiff.y<<endl;
		cerr<<"term: "<<term.x<<" "<<term.y<<endl;
		//------------------------------------------------
	}
	velocity.normalize();
	if(self.velocity.scalarProd(velocity)>MAX_SPEED)
		velocity=self.velocity.times(-1);
	return self.position.plus(velocity);
}
int main(){
	int playerId; // your id (0 to 4)
	cin >> playerId; cin.ignore();

	while (1) {
		int playerChipCount;
		cin >> playerChipCount; cin.ignore();
		int entityCount;
		vector<Object>  objects;
		vector<Object>  players;
		vector<Object>  oils;
		vector<Object>  goods;
		vector<Object>  bads;
		cin >> entityCount; cin.ignore();
		for (int i = 0; i < entityCount; i++) {
			Object object;
			cin >> object.id >> object.player >> object.radius >> object.position.x >>object.position. y >> object.velocity.x >> object.velocity.y; cin.ignore();
			objects.push_back(object);
			if(object.player==-1)
				oils.push_back(object);
			else
				players.push_back(object);
			if(object.player==playerId)
				goods.push_back(object);
			else
				bads.push_back(object);
		}
		for (int i = 0; i < playerChipCount; i++) {
			Vector to = inteligence(goods[i],objects);
			if(to.norm()!=0.0f)
				cout <<to.x<<" "<<to.y<< endl; // One instruction per chip: 2 real numbers (x y) for a propulsion, or 'WAIT'.
			else
				cout <<"WAIT"<< endl; // One instruction per chip: 2 real numbers (x y) for a propulsion, or 'WAIT'.
		}
	}
}
