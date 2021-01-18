class Driver(){
	public:
		void run();
}

class User {
	private:
		string id, name, email, mobile;

	public:
		void displayStats();
		void updateExpense(string userId, amount);
}

class ExpenseManager{

	private:
		map<string , float> userSplits;
		map<string, User*> userMap;
		Split *split;

	public:
		void updateExpense(string sourceUserId,float amount,vector<string> &splitUsers,string splitStrategy);
		void display(string userId);
		void display();
}

class Split {
	public:
		Split();
		vector<float> splitExpense(string sourceUserId,float amount,vector<string> &splitUsers,string splitStrategy);

	private:
		ExactSplit *exactSplitObj;
		PercentSplit *percentSplitObj;
		EqualSplit *equalSplitObj;
}

class ISplitStrategy {
	virtual void split() = 0;
}

class ExactSplit: public ISplitStrategy{
	void split();
}

class PercentSplit: public ISplitStrategy{
	void split();
}

class EqualSplit: public ISplitStrategy{
	void split();
}
