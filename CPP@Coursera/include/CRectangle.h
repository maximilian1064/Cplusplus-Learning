/*Class for static member properties test*/

class CRectangle
{
private:
	int area;
	int whatever;
	static int totalNumber;
	static int totalArea;
public:
	CRectangle(int i, int j=0);
	CRectangle(CRectangle& r);
	// CRectangle(double a){ area = a; whatever = 0; }
	~CRectangle();
	static void printTotal();
};

CRectangle::CRectangle(int i, int j)
{
	area = i;
	whatever = j;
	totalNumber++;
	totalArea += area;
	std::cout << "cons called" << std::endl;
	std::cout << "total number + :" << totalNumber << std::endl;
}

CRectangle::CRectangle(CRectangle& r)
{
	area = r.area;
	whatever = r.whatever;
	totalNumber++;
	totalArea += area;
	std::cout << "copy cons called" << std::endl;
	std::cout << "total number + :" << totalNumber << std::endl;
}

CRectangle::~CRectangle()
{
	totalNumber--;
	totalArea -= area;
	std::cout << "total number - :" << totalNumber << std::endl;
}

void CRectangle::printTotal()
{
	std::cout << "total number:" << totalNumber << std::endl;
	std::cout << "total area:" << totalArea << std::endl;
}
