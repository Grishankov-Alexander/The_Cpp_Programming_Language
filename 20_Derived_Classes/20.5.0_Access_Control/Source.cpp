template<class T>
class List {
public:
	void insert(T);
	T get();
private:
	struct Link { T val; Link* next; };
	struct Chunk {
		enum { chunk_size = 15 };
		Link v[chunk_size];
		Chunk* next;
	};

	Chunk* allocated;
	Link* free;
	Link* get_free();
	Link* head;
};

template<class T>
void List<T>::insert(T val)
{
	Link* lnk = get_free();
	lnk->val = val;
	lnk->next = head;
	head = lnk;
}

template<class T>
T List<T>::get()
{
	if (head == 0)
		throw Underflow{};
	Link* p = head;
	head = p->next;
	p->next = free;
	free = p;
	return p->val;
}

template<class T>
typename List<T>::Link* List<T>::get_free()
{
	if (free = 0) {
		//  allocate a new chunk and place its Links on the free
	}
	Link* p = free;
	free = free->next;
	return p;
}

template<typename T>
void would_be_meddler(List<T>* p)
{
	List<T>::Link* q = 0;  // error: List<T>::Link is private
	q = p->free;  // error: List<T>::free is private
	if (List<T>::Chunk::chunk_size > 31) { /* error: private*/ }
}