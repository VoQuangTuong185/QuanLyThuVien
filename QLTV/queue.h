template <typename Type>
struct Queue{
	int n;
	int fr, rear;
	Type *nodes;//mang 1 chieu cap phat dong

	Queue(){
		n = 0;
		fr = 0; rear = 0;
		nodes = new Type[QUEUE_CAPACITY];
	}
	~Queue(){
		delete[] nodes;
	}		
	bool empty(){
		return n == 0;
	}
	Type front(){
		return nodes[fr];
	}	
	void push(Type value){
		if(n >= QUEUE_CAPACITY) return;
		nodes[rear] = value;
		rear++;
		n++;
	}	
	void pop(){
		if(empty()) return;
		else{
			fr++;
			n--;
		}
	}
};
