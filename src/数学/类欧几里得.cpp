const LL p=998244353;
LL i2=499122177,i6=166374059;//2^(-1),6^(-1)
struct data{
	data(){f=g=h=0;}
	LL f,g,h;
};
data calc(LL n,LL a,LL b,LL c){
	LL ac=a/c,bc=b/c,m=(a*n+b)/c,n1=n+1,n21=n*2+1;
	data d;
	if(!a){
		d.f=bc*n1%p;
		d.g=bc*n%p*n1%p*i2%p;
		d.h=bc*bc%p*n1%p;
		return d;
	}
	if(a>=c||b>=c){
		d.f=n*n1%p*i2%p*ac%p+n1*bc%p;
		d.g=ac*n%p*n1%p*n21%p*i6%p+bc*n%p*n1%p*i2%p;
		d.h=ac*ac%p*n%p*n1%p*n21%p*i6%p+bc*bc%p*n1%p+ac*bc%p*n%p*n1%p;
		d.f%=p,d.g%=p,d.h%=p;
		data e=calc(n,a%c,b%c,c);
		d.h+=e.h+2*bc%p*e.f%p+2*ac%p*e.g%p;
		d.g+=e.g,d.f+=e.f;
		d.f%=p,d.g%=p,d.h%=p;
		return d;
	}
	data e=calc(m-1,c,c-b-1,a);
	d.f=n*m%p-e.f,d.f=(d.f%p+p)%p;
	d.g=m*n%p*n1%p-e.h-e.f,d.g=(d.g*i2%p+p)%p;
	d.h=n*m%p*(m+1)%p-2*e.g-2*e.f-d.f,d.h=(d.h%p+p)%p;
	return d;
}
