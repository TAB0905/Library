template<typename T>
struct Point {
  T x, y;
  Point(T x, T y) : x(x), y(y) {}
  Point operator+(Point rhs) const {
    return Point(*this) += rhs;
  }
  Point operator-(Point rhs) const {
    return Point(*this) -= rhs;
  }
  Point operator*(T c) const {
    return Point(*this) *= c;
  }
  Point operator/(T c) const {
    return Point(*this) /= c;
  }
  Point operator+=(Point rhs){
    x += rhs.x;
    y += rhs.y;
    return *this;
  }
  Point operator-=(Point rhs){
    x -= rhs.x;
    y -= rhs.y;
    return *this;
  }
  Point operator*=(T c){
    x *= c;
    y *= c;
    return *this;
  }
  Point operator/=(T c){
    x /= c;
    y /= c;
    return *this;
  }
};

template<typename T>
T dot(Point<T> a, Point<T> b){
  return a.x*b.x + a.y*b.y;
}

template<typename T>
T cross(Point<T> a, Point<T> b){
  return a.x*b.y - a.y*b.x;
}

template<typename T>
T norm(Point<T> a){
  return dot(a,a);
}

template<typename P>
int ccw(P a, P b, P c){
  b -= a; c -= a;
  if(cross(b,c) > 0) return +1;
  if(cross(b,c) < 0) return -1;
  if(dot(b,c) < 0) return +2;
  if(norm(b) < norm(c)) return -2;
  return 0;
}

