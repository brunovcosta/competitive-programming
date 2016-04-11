#include<bits/stdc++.h>
using namespace std;

struct Vetor{
	double x,y,z;
	Vetor(void);
	Vetor(double x,double y,double z);
	double distancia(Vetor outro);
	Vetor menos(Vetor outro);
	Vetor vezes(double fator);
	Vetor prodVet(Vetor outro);
	double prodEsc(Vetor outro);
	double norma();
	Vetor versor();
};
Vetor::Vetor(void){
	this->x=0;
	this->y=0;
	this->z=0;
}
Vetor::Vetor(double x,double y,double z){
	this->x=x;
	this->y=y;
	this->z=z;
}
double Vetor::distancia(Vetor outro){
	double dx=this->x-outro.x;
	double dy=this->y-outro.y;
	double dz=this->z-outro.z;
	return sqrt(dx*dx+dy*dy+dz*dz);
}
Vetor Vetor::menos(Vetor outro){
	return Vetor(this->x-outro.x,this->y-outro.y,this->z-outro.z);
}
Vetor Vetor::vezes(double fator){
	return Vetor(fator*this->x,fator*this->y,fator*this->z);
}
Vetor Vetor::prodVet(Vetor outro){
	/* |  i  j  k |
	 * | px py pz |
	 * | qx qy qz |
	 */
	double x = this->y*outro.z-this->z*outro.y;
	double y = this->z*outro.x-this->x*outro.z;
	double z = this->x*outro.y-this->y*outro.x;
	return Vetor(x,y,x);
}
double Vetor::prodEsc(Vetor outro){
	double x=this->x*outro.x;
	double y=this->x*outro.y;
	double z=this->x*outro.z;
	return x+y+z;
}
double Vetor::norma(){
	double xx=this->x*this->x;
	double yy=this->y*this->y;
	double zz=this->z*this->z;
	return sqrt(xx+yy+zz);
}
Vetor Vetor::versor(){
	double x=this->x;
	double y=this->y;
	double z=this->z;
	double norma = this->norma();
	return Vetor(x/norma,y/norma,z/norma);
}
int orient(Vetor a, Vetor b, Vetor c){
	return b.x*c.y - b.y*c.x - (a.x*c.y - a.y*c.x) + a.x*b.y - a.y*b.x;
}
set<Vetor > convexHull(set<Vetor > in){
	if (in.size() <= 2){
		return in;
	}
	set<Vetor > top, down;
	top.insert(*in.begin());
	top.insert(*(++in.begin()));
	down.insert(*in.begin());
	down.insert(*(++in.begin()));

	for (set<Vetor >::iterator it = ++++in.begin(); it != in.end(); it++){
		while (top.size() >= 2 && orient(*it, *(--top.end()), *(----top.end())) < 0)
			top.erase(*(--top.end()));
		top.insert(*it);
	}

	for (set<Vetor >::iterator it = ++++in.begin(); it != in.end(); it++){
		while (down.size() >= 2 && orient(*it, *(--down.end()), *(----down.end())) > 0)
			down.erase(*(--down.end()));
		down.insert(*it);
	}
	for (set<Vetor >::iterator it = down.begin(); it != down.end(); it++)
		top.insert(*it);
	return top;
}
int main(){
	for(;;){
		int n;
		scanf("%d",&n);
		if(!n)break;
		set<Vetor> pontos;
		for(int i=0;i<n;i++){
			int x,y;
			scanf("%d%d",&x,&y);
			Vetor ponto(x,y)
			pontos.insert(ponto);
		}
		double tamanho=0;
		for (set<Vetor >::iterator it = ++++in.begin(); it != in.end(); it++){
			tamanho+=it=>distancia(*(it+1));
		}
		printf("%lf",tamanho);
	}

}
