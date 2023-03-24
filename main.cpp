#include <iostream>
using namespace std;

int whereP(double &x, double &y, double a);
void putP(double x, double y);
int proccesP(double x, double y, double a);
bool getP(double& x, double& y);
void aboutA();
bool getCont(double& a);
void proccesCont(double a);
void putResult(double a, double x, double y, int r);

int main()
{
 aboutA();
 double a;
 if (getCont(a) == 0)
 {
  cout << "CONTOUR IS ABSENT" << endl;
  cout << "END OF WORK" << endl;
  return 0;
 }
 proccesCont(a);

}

void aboutA() {  
    cout << "Laboratory work 1-1. Point and outline.\nK-14 Vasylenko Zlata\n";  
}
bool getCont(double& a)
{
 cout << "Enter coeficient of contour:" << endl;
 if (!(cin >> a) || (a < 0))
 {
  cout << "ERROR" << endl;
  return 0;
 }
 else 
  return 1;
}
bool getP(double& x, double& y) { 
    cout << "Enter the coordinates with a space: "; 
    if (cin >> x >> y) { 
        return true; 
    } 
    else { 
        return false; 
    } 
} 
void putP(double x, double y)
{
 cout << '(' << x << ';' << y << ')';
}
int whereP(double& x, double& y, double a) { 
    if  ( 
        (x==a) && (y>=0 && y<= 2*a) || 
        (y==2*a) && (x>=0 && x<=a) || 
        (x==0) && (y>=a && y<= 2*a)|| 
        (x>=0 && x<=a) && y==(a-x)){ 
        return 0; 
    } 
    else if   ( 
        (x>0 && x<a) && (y>=a && y<= 2*a)|| 
        (x>0 && x<a) && (y>(a-x) && y<a)){ 
        return -1; 
    } 
    else { 
        return 1; 
    } 
} 

int proccesP(double x, double y, double a)
{
 int r = whereP(x,y,a);
 if (r == (-1)) { return -1; }
 else if (r == 0) {return 0; }
 else {return 1; }
}
void proccesCont(double a)
{
 double x, y;
 while (getP(x, y))
 {
  int r = whereP(x,y,a);
  putResult(a, x, y, r);
 }
 if (getP(x, y) == 0)
 {
  cout << "END OF POINTS" << endl;
 }
}
void putResult(double x, double y, double a, int r)
{
 putP(y,a);
 if (r == (-1)) { cout<< "IN_C "; }
 else if (r == 0) {cout<<"ON_C "; }
 else {cout<<"OUT_C "; }
cout<<x<<"\n";
}
