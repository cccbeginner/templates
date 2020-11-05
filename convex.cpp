#define pii pair<int,int>
#define x first
#define y second

int cross(pii a, pii o, pii b){
	return (o.x-a.x) * (b.y-o.y) - (o.y-a.y) * (b.x-o.x);
}

int n;
vector<pii> dots;
vector<pii> find_convex(){
    cin >> n;
    dots.resize(n);
	for(int i = 0; i < n; ++i)cin >> dots[i].x >> dots[i].y;
	vector<pii> v;
	sort(dots, dots+n);
	for(int i = 0; i < n; ++i){
		while(v.size() >= 2 && cross(v[v.size()-2], v[v.size()-1], dots[i]) > 0)v.pop_back();
		v.emplace_back(dots[i]);
	}
	v.pop_back();
	int t = v.size();
	for(int i = n-1; i >= 0; --i){
		while(v.size() >= t+2 && cross(v[v.size()-2], v.back(), dots[i]) > 0)v.pop_back();
		v.emplace_back(dots[i]);
	}
	v.pop_back();
	return v;
}
