cylinder::cylinder(float a,float b,float r,float h):circle(a,b,r),height(h){}

void cylinder::setHeight(float h) { height = h; }

float cylinder::getHeight() const { return height; }

float cylinder::area() const { return 2 * circle::area() + 2 * 3.1415 * radius * height; }

float cylinder::volume() const { return circle::area() * height; }

ostream& operator<<(ostream &output, const cylinder &cy)
{
    output << "Center=[" << cy.x << "," << cy.y << "], r=" << cy.radius << ", h=" << cy.height << "\narea=" << cy.area() << ", volume=" << cy.volume() << endl;
    return output;
}