void extgcd(int a, int b, int &x, int &y){
	if(b == 0){
		x = 1;
		y = 0;
	}else{
		extgcd(b, a%b, y, x);
		y -= (a/b) * x;
	}
}

int moni(int k, int mod){
	int x,y;
	extgcd(k, mod, x, y);
	return (x%mod+mod) % mod;
}
