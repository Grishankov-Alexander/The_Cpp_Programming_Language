struct Readout1 {
	char hour;  // [0:23]
	int value;
	char seq;  // sequence mark ['a':'z']
};
bool b1 = sizeof(Readout1) == 12;

struct Readout2 {
	int value;
	char hour;
	char seq;
};
bool b2 = sizeof(Readout2) == 8;