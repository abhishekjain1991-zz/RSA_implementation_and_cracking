// Implementation of the RSA public-key encryption algorithm
// ECE4893/ECE8893, Fall 2013
// ABHISHEK JAIN 
// //GTID 902985939

#include <iostream>
#include <gmpxx.h>


using namespace std;


gmp_randclass randm(gmp_randinit_default);
int SIZE=32; 

void GetPrime(mpz_class& p, unsigned long sz, unsigned long c)
{ 
  while(1)
    {
      p = randm.get_z_bits(sz);
      if (mpz_probab_prime_p(p.get_mpz_t(), c)) return;
    }
}
void setValues(mpz_class& n, mpz_class& d, mpz_class& e)
{ 
  mpz_class p,q,r,p1,q1,fi;
  GetPrime(p, SIZE, 100);
  GetPrime(q, SIZE, 100);

  n = p * q;
 cout<<" p is \n"<<p<<endl;
 cout<<"q is  \n"<<q<<endl;
  p1 = p - 1;
  q1 = q - 1;
  fi = p1 * q1;
  cout <<"finding d"<<endl;
   while(1) 
    {
    
      GetPrime(d,2*SIZE,100);
	mpz_gcd(r.get_mpz_t(),fi.get_mpz_t(),d.get_mpz_t());
	if(d<fi && n%d!=0 && r==1) break;
    }

  cout<<"Got d"<<d<<endl;
  cout<<"finding e"<<endl;
  mpz_invert(e.get_mpz_t(), d.get_mpz_t(), fi.get_mpz_t());
  cout<<"got e"<<endl;
}

void EnDecrypt(mpz_class& C, mpz_class& M, mpz_class& d, mpz_class& n)
{ // used for encrytion and decryption
  mpz_powm(C.get_mpz_t(), M.get_mpz_t(), d.get_mpz_t(), n.get_mpz_t());
}

int main()
{
for(;SIZE<=1024;SIZE=SIZE*2)
{  mpz_class n;
  mpz_class d;
  mpz_class e;
for(int m=0;m<100;m++)
  {setValues(n, d, e);
 for (int k = 0; k < 100; ++k)
    {
      mpz_class Mes, Code,  Decode,crackcode,gcd;
      mpz_class x=2,y=2,z,de=1,dy=1,dz=1,cfi,ce;
      Mes = randm.get_z_bits((2*SIZE)-8);

	EnDecrypt(Code, Mes, d, n);  // encrypted message
     EnDecrypt(Decode, Code, e, n);  // decrypted message  
    if (Mes != Decode)
        { 
          cout<<"Either Encryption or Decryption failed " << endl;
          cout<<"Code is "<<Code << endl;
          cout<<"Mesa is "<<Mes << endl;
          cout<<"Dmes is "<<Decode << endl;
        }
      else
        {
          cout<< "Encryption and Decryption work "<<endl;
        }
      cout<<"Code is "<<Code<<endl;
      cout<<"Mesa is "<<Mes<< endl;
      cout<<"Dmes is "<<Decode<< endl;
if(SIZE<=32){
     // cout<<"lets try breaking it \n";



while(dz==1)
{x=((x*x)-1)%n;
//cout<<"x is "<<x<<endl;
//cout<<"num is "<<n<<endl;
y=(((y*y-1)*(y*y-1))-1)%n;
//cout<<"y is "<<y<<endl;
z=x-y;
mpz_abs(de.get_mpz_t(),z.get_mpz_t());
//cout<<"absoulute value of z is \n"<<de<<endl;
mpz_gcd(dz.get_mpz_t(),n.get_mpz_t(),de.get_mpz_t());
//cout<<"calculating";
}
dy=n/dz;



//cout<<"one factor is "<<dz<<endl;
//cout<<"other factor is "<<dy<<endl;
//cout<<"calculating phi "<<endl;
cfi=(dz-1)*(dy-1);
mpz_invert(ce.get_mpz_t(), d.get_mpz_t(), cfi.get_mpz_t());
EnDecrypt(crackcode, Code, ce, n);
cout<<"cracked"<<endl;
      	  cout<<"Code is "<<Code<< endl;
          cout<<"Mesa  is "<<Mes<< endl;
          cout<<"cracked Message is " <<crackcode<< endl;

}
}
}

cout<<"done for size "<<SIZE<<endl;
}
}


