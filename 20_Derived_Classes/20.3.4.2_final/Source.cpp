
class Type;
struct Node {  // interface class
	virtual Type type() = 0;
};

class if_statement : public Node {
	Type type() override final;  // prevent further overriding
};
class Modified_if_statement : public if_statement {
	Type type() override;  // error: if_statement::type() is final
};

class For_statement final : public Node {
	Type type() override;
};

class Modified_for_statement : public For_statement {  // error: For_statement is final class
	Type type() override;
};

int final = 7;
class Base {
	virtual int f() = 0;
};
struct Dx : Base {
	int f() override final
	{
		return final + ::final;
	}
	int final;
};