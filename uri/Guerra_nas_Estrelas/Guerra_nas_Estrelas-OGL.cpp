#include<cstdio>
#include<GL/glut.h>
#include<GL/gl.h>
#include<GL/glu.h>
#include<cmath>
#include<vector>
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
double distVetorFace(Vetor p, Vetor f1, Vetor f2, Vetor f3){
	Vetor diff = f1.menos(p);
	Vetor perp = f2.menos(f1).prodVet(f3.menos(f1)).versor();
	Vetor proj = perp.vezes(diff.prodEsc(perp));
	return proj.norma();
}
struct Nave{
	Vetor p1,p2,p3,p4;
	Nave(Vetor p1,Vetor p2,Vetor p3,Vetor p4);
	double distancia(Nave outra);
};
Nave::Nave(Vetor p1,Vetor p2,Vetor p3,Vetor p4){
	this->p1=p1;
	this->p2=p2;
	this->p3=p3;
	this->p4=p4;
}
double gradientDescent(Nave naveP, Nave naveQ, double a1,double a2,double a3,double a4,double b1, double b2, double b3, double b4,int passos){
	/* p = a12*p1+a22*p2+a32*p3+a42*p4
	 * q = b12*q1+b22*q2+b32*q3+b42*q4
	 *
	 * d = sqrt((px-qx)2+(py-qy)2+(pz-qz)2)
	 */
	double gama = 0.001;

	double px1 = naveP.p1.x;
	double px2 = naveP.p2.x;
	double px3 = naveP.p3.x;
	double px4 = naveP.p4.x;
	double qx1 = naveQ.p1.x;
	double qx2 = naveQ.p2.x;
	double qx3 = naveQ.p3.x;
	double qx4 = naveQ.p4.x;

	double py1 = naveP.p1.y;
	double py2 = naveP.p2.y;
	double py3 = naveP.p3.y;
	double py4 = naveP.p4.y;
	double qy1 = naveQ.p1.y;
	double qy2 = naveQ.p2.y;
	double qy3 = naveQ.p3.y;
	double qy4 = naveQ.p4.y;

	double pz1 = naveP.p1.z;
	double pz2 = naveP.p2.z;
	double pz3 = naveP.p3.z;
	double pz4 = naveP.p4.z;
	double qz1 = naveQ.p1.z;
	double qz2 = naveQ.p2.z;
	double qz3 = naveQ.p3.z;
	double qz4 = naveQ.p4.z;

	double px = (a1*a1*px1+ a2*a2*px2+ a3*a3*px3+ a4*a4*px4)/(a1*a1+ a2*a2+ a3*a3+ a4*a4);
	double py = (a1*a1*py1+ a2*a2*py2+ a3*a3*py3+ a4*a4*py4)/(a1*a1+ a2*a2+ a3*a3+ a4*a4);
	double pz = (a1*a1*pz1+ a2*a2*pz2+ a3*a3*pz3+ a4*a4*pz4)/(a1*a1+ a2*a2+ a3*a3+ a4*a4);
	double qx = (b1*b1*qx1+ b2*b2*qx2+ b3*b3*qx3+ b4*b4*qx4)/(b1*b1+ b2*b2+ b3*b3+ b4*b4);
	double qy = (b1*b1*qy1+ b2*b2*qy2+ b3*b3*qy3+ b4*b4*qy4)/(b1*b1+ b2*b2+ b3*b3+ b4*b4);
	double qz = (b1*b1*qz1+ b2*b2*qz2+ b3*b3*qz3+ b4*b4*qz4)/(b1*b1+ b2*b2+ b3*b3+ b4*b4);

	double dist = Vetor(px,py,pz).distancia(Vetor(qx,qy,qz));
	//printf("-------------------------\n");
	//printf("%lf\n",dist);
	//printf("-------------------------\n");

	double da1 = -gama*a1*(px1*(px-qx) +py1*(py-qy) +pz1*(pz-qz))/dist;
	double da2 = -gama*a2*(px2*(px-qx) +py2*(py-qy) +pz2*(pz-qz))/dist;
	double da3 = -gama*a3*(px3*(px-qx) +py3*(py-qy) +pz3*(pz-qz))/dist;
	double da4 = -gama*a4*(px4*(px-qx) +py4*(py-qy) +pz4*(pz-qz))/dist;
	double db1 = +gama*b1*(qx1*(px-qx) +qy1*(py-qy) +qz1*(pz-qz))/dist;
	double db2 = +gama*b2*(qx2*(px-qx) +qy2*(py-qy) +qz2*(pz-qz))/dist;
	double db3 = +gama*b3*(qx3*(px-qx) +qy3*(py-qy) +qz3*(pz-qz))/dist;
	double db4 = +gama*b4*(qx4*(px-qx) +qy4*(py-qy) +qz4*(pz-qz))/dist;

	if(passos<0){
		return dist;
	}else{
		return gradientDescent(naveP,naveQ,
			a1+da1, a2+da2, a3+da3, a4+da4,
			b1+db1, b2+db2, b3+db3, b4+db4, passos-1);
	}

}
double Nave::distancia(Nave outra){
	return gradientDescent(*this,outra,1,1,1,1,1,1,1,1,8000);
}
vector<Nave> naves;
void desenha(){


	//glLoadIdentity(); 
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glDepthFunc(GL_LESS);
	glBegin(GL_TRIANGLES);
	for(int i=0;i<naves.size();i++){
		Vetor p1 = naves[i].p1;
		Vetor p2 = naves[i].p2;
		Vetor p3 = naves[i].p3;
		Vetor p4 = naves[i].p4;
		Vetor permut[4][3] = {
			{p2,p3,p4},
			{p1,p3,p4},
			{p1,p2,p4},
			{p1,p2,p3}
		};
		for(int j=0;j<4;j++){
			glColor3f(1.0f/(i+1),1.0f/(j+1),1.0f/(i*j+1));
			for(int k=0;k<3;k++){
				glVertex3f((float)permut[j][k].x/10,(float)permut[j][k].y/10,(float)permut[j][k].z/10);
			}
		}
	}
	glEnd();
	glFlush();
}
int prev_x,prev_y;
void mouse_move(int x,int y){
	glRotatef( x-prev_x, 0, 0, 1 );
	glRotatef( y-prev_y, 0, 1, 0 );

	prev_x=x;
	prev_y=y;

	desenha();
}
int main(int argc, char **argv){
	int n;
	scanf("%d",&n);
	int i;
	for(i=0;i<n;i++){
		double x11,y11,z11;
		double x12,y12,z12;
		double x13,y13,z13;
		double x14,y14,z14;
		double x21,y21,z21;
		double x22,y22,z22;
		double x23,y23,z23;
		double x24,y24,z24;
		Vetor p11=Vetor(x11,y11,z11);
		Vetor p12=Vetor(x12,y12,z12);
		Vetor p13=Vetor(x13,y13,z13);
		Vetor p14=Vetor(x14,y14,z14);
		Vetor p21=Vetor(x21,y21,z21);
		Vetor p22=Vetor(x22,y22,z22);
		Vetor p23=Vetor(x23,y23,z23);
		Vetor p24=Vetor(x24,y24,z24);
		Nave nave1 = Nave(p11,p12,p13,p14);
		Nave nave2 = Nave(p21,p22,p23,p24);
		
		scanf("%lf%lf%lf",&x11,&y11,&z11);
		scanf("%lf%lf%lf",&x12,&y12,&z12);
		scanf("%lf%lf%lf",&x13,&y13,&z13);
		scanf("%lf%lf%lf",&x14,&y14,&z14);
		scanf("%lf%lf%lf",&x21,&y21,&z21);
		scanf("%lf%lf%lf",&x22,&y22,&z22);
		scanf("%lf%lf%lf",&x23,&y23,&z23);
		scanf("%lf%lf%lf",&x24,&y24,&z24);
		printf("%.2lf\n",nave1.distancia(nave2));

		naves.push_back(nave1);
		naves.push_back(nave2);
	}
	glutInit(&argc,argv);
	glutCreateWindow("GUERRA NAS ESTRELAS");
	glutInitDisplayMode(GLUT_RGB | GLUT_DEPTH);
	glEnable(GL_DEPTH_TEST);
	glDepthMask(GL_TRUE);
	glDepthFunc(GL_LEQUAL);
	glDepthRange(0.0f, 1.0f);
	glutDisplayFunc(desenha);
	glutMotionFunc(mouse_move);
	glClearColor(0,0,0,0);
	glutMainLoop();
	return 0;
}
