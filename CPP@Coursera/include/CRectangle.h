/*Class for static member properties test*/



class CRectangle
{
private:
	int area;
	static int totalNumber;
	static int totalArea;
public:
	CRectangle(int i);
	CRectangle(CRectangle& r);
	~CRectangle();
	static void printTotal();
};

CRectangle::CRectangle(int i)
{
	area = i;
	totalNumber++;
	totalArea += area;
}

CRectangle::CRectangle(CRectangle& r)
{
	area = r.area;
	totalNumber++;
	totalArea += area;
}

CRectangle::~CRectangle()
{
	totalNumber--;
	totalArea -= area;
}

static void CRectangle::printTotal()
{
	std::cout << "total number:" << totalNumber << std::endl;
	std::cout << "total area:" << totalArea << std::endl;
}
