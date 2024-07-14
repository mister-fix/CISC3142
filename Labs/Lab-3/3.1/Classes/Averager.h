class Averager {
	public:
		Averager();
		int getSum();
		void add(int);
		int getCount();
		double getAverage();
		
	private:
		int sum;
		int count;
};