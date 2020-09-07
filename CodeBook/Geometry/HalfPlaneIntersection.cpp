// LatexBegin
typedef pdd Point;
typedef vector<Point> Polygon;
typedef pair<Point,Point> Line;
#define N 10
#define p1 first
#define p2 second
pdd operator-(const pdd &a,const pdd &b){
	return mp(a.x-b.x,a.y-b.y);
}
pdd operator+(const pdd &a,const pdd &b){
	return mp(a.x+b.x,a.y+b.y);
}
pdd operator*(const pdd &a,const double &b){
	return mp(b*a.x,b*a.y);
}
double cross(Point a, Point b){
	return a.x * b.y - a.y * b.x;
}
double cross(Point o, Point a, Point b){
	return cross(a-o,b-o);
}
double cross(Line l, Point p){
    return cross(l.p1, l.p2, p);
}
double arg(const pdd &a){
	return atan2(a.y,a.x);
}
bool parallel(Line l1, Line l2){
    return cross(l1.p2 - l1.p1, l2.p2 - l2.p1) < 1e-8&&cross(l1.p2 - l1.p1, l2.p2 - l2.p1) > -1e-8;
}
Point intersection(Line l1, Line l2){
    Point& a1 = l1.p1, &a2 = l1.p2;
    Point& b1 = l2.p1, &b2 = l2.p2;
    Point a = a2 - a1, b = b2 - b1, s = b1 - a1;
    return a1 + a * (cross(b, s) / cross(b, a));
}
bool cmp(Line l1, Line l2){
    return arg(l1.p2 - l1.p1) < arg(l2.p2 - l2.p1);
}
Polygon halfplane_intersection(vector<Line> hp){
    sort(hp.begin(), hp.end(), cmp);
    int L = 0, R = 0;
    vector<Line> l(N);
	vector<Point> p(N);
    l[R] = hp[0];
    for (int i=1; i<hp.size(); i++)
    {
        while (L < R && cross(hp[i], p[R-1]) < 0) R--;
        while (L < R && cross(hp[i], p[L])   < 0) L++;
        l[++R] = hp[i];
        if (parallel(l[R-1], hp[i]) &&
            cross(l[--R], hp[i].p1) > 0) l[R] = hp[i];
        if (L < R) p[R-1] = intersection(l[R], l[R-1]);
    }
    while (L < R && cross(l[L], p[R-1]) < 0) R--;
    if (R-L <= 1) return Polygon();//printf("?");
    if (L < R) p[R] = intersection(l[L], l[R]);
    Polygon ch;
    for (int i=L; i<=R; i++) ch.push_back(p[i]);
    ch.resize(unique(ch.begin(), ch.end()) - ch.begin());
    if (ch.size() > 1 && ch.front() == ch.back())
        ch.pop_back();
    return ch;
}
double cal(Polygon p){
	if(p.empty())
	return 0;
	p.pb(*p.begin());
	double ans=0;
	for(int i=0;i<p.size()-1;i++){
		ans+=p[i].x*p[i+1].y;
		ans-=p[i].y*p[i+1].x;
	}
	ans/=2;
	ans=abs(ans);
	return ans;
}
// LatexEnd
