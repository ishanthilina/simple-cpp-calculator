#include <vector>

using namespace std;

class InputTokenizer
{
public:
	vector<string> getInputTokens();
	InputTokenizer(char);
protected:
private:
	char seperator;

};


