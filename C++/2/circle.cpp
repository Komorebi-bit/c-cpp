circle::circle(float a, float b, float r) : point(a,b), radius(r){}
void circle::setRadius(float r)
{
    radius = r;
}
float circle::getRadius() const { return radius; }

float circle::area() const { return 3.1415 * radius * radius; }

ostream& operator<<(ostream &output, const circle &c)
{
    output << "Center=[" << c.x << "," << c.y << "],r=" << c.radius << ", area=" << c.area() << endl;
    return output;
}