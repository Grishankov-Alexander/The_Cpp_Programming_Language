struct PPN {  // R6000 Physical Page Number
	unsigned int PFN : 22;  // Page Frame Number
	int : 3;  // unused
	unsigned int CCA : 3;  // Cache Coherency Algorithm
	bool nonreachable : 1;
	bool dirty : 1;
	bool valid : 1;
	bool global : 1;
};

void part_of_VM_system(PPN* p)
{
	if (p->dirty) {  // contents changed
		// copy to disk
		p->dirty = 0;
	}
}