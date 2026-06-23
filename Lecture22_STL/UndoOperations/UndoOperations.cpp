#include <iostream>
#include <forward_list>
#include <string>

class Operation
{
public:
	Operation(std::string operationName) : m_operationName(operationName) {}

	virtual void execute() { std::cout << "Executing operation " << m_operationName; }
	virtual void undo() { std::cout << "Undoing operation "  << m_operationName; }

	~Operation() = default;

private:
	std::string m_operationName;
	//...
};
int main()
{
	std::forward_list<Operation*> operationsLog;

	Operation* save = new Operation{ "Save doc" };
	Operation* formatDoc = new Operation{ "Format style doc" };
	Operation* fixPunctuation = new Operation{ "Fix punctuation" };

	formatDoc->execute();
	operationsLog.push_front(formatDoc);

	fixPunctuation->execute();
	operationsLog.push_front(fixPunctuation);

	//...
	Operation* lastOperationToUndo = operationsLog.front();
	lastOperationToUndo->undo();
	operationsLog.pop_front();
}
