point::point(float a, float b)
{
    x = a;
    y = b;
}
void point::setPoint(float a,float b)
{
    x = a;
    y = b;
}
ostream & operator<<(ostream &output,const point &p)
{
    output << "[" << p.x << "," << p.y << "]" << endl;
    return output;
}