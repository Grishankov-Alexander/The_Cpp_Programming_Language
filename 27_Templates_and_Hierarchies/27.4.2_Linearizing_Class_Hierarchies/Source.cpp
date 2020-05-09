

namespace ipr {  // interface

	struct Node;
	enum Category_code;
	class Visitor;

	struct Expr;
	class Type;

	struct Stmt;
	class Unit_location;
	class Source_location;
	class Annotation;
	template<typename T>
	class Sequence;

	struct Decl;
	class Linkage;
	class Name;
	class Region;

	struct Var;
	template<Category_code Cat, typename T = Expr>
	struct Category;

	class Substitution;
}

struct ipr::Node {
	const int node_id;
	const Category_code category;

	virtual void accept(Visitor&) const = 0;  // hook for visitor classes
protected:
	Node(Category_code);
};

struct ipr::Expr : Node {
	virtual const Type& type() const = 0;
protected:
	Expr(Category_code c) : Node(c) {}
};

struct ipr::Stmt : Expr {
	virtual const Unit_location& unit_location() const = 0;  // line in file
	virtual const Source_location& source() const = 0;

	virtual const Sequence<Annotation>& annotation() const = 0;
protected:
	Stmt(Category_code c) : Expr(c) {}
};

struct ipr::Decl : Stmt {
	enum Specifier {};  // storage class, virtual, access control
	
	virtual Specifier specifiers() const = 0;
	virtual const Linkage& lang_linkage() const = 0;
	virtual const Name& name() const = 0;
	virtual const Region& home_region() const = 0;
	virtual const Region& lexical_region() const = 0;
	virtual bool has_initializer() const = 0;
	virtual const Expr& initializer() const = 0;
protected:
	Decl(Category_code c) : Stmt{ c } {}
};

enum ipr::Category_code { var_cat = 1 };

template<ipr::Category_code Cat, typename T>
struct ipr::Category : T {
protected:
	Category() : T{ Cat } {}
};

struct ipr::Var : Category<var_cat, Decl> {};


namespace impl {  // implementation
	template<typename T> struct Node;
	template<typename T> struct Expr;
	template<typename T> struct Stmt;
	template<typename T> struct Decl;
	struct Var;

	template<typename T> class basic_decl_data;
}

template<typename T>
struct impl::Node : T {
	using Interface = T;
	void accept(ipr::Visitor& v) const override { v.visit(*this); }
};

template<typename T>
struct impl::Expr : Node<T>
{
	const ipr::Type* constraint;  // type of the expression
	Expr() : constraint(0) {}
	const ipr::Type& type() const override { return *util::check(constraint); }
};

template<typename T>
struct impl::Stmt : Expr<T> {
	ipr::Unit_location unit_locus;
	ipr::Source_location src_locus;
	ipr::Sequence<ipr::Annotation> notes;

	const ipr::Unit_location& unit_location() const override { return unit_locus; }
	const ipr::Source_location& source() const override { return src_locus; }
	const ipr::Sequence<ipr::Annotation>& annotation() const override { return notes; }
};

template<typename T>
struct impl::Decl : Stmt<T> {
	basic_decl_data<T> decl_data;
	ipr::Sequence<ipr::Substitution> args;

	Decl() : decl_data(0) {}

	const ipr::Sequence<ipr::Substitution>& substitutions() const { return args; }
	const ipr::Linkage& lang_linkage() const override;
	const ipr::Region& home_region() const override;
};

struct impl::Var : Decl<ipr::Var> {
	const ipr::Expr* init;
	const ipr::Region* lexreg;

	Var();

	bool has_initializer() const override;
	const ipr::Expr& initializer() const override { return *init; }
	const ipr::Region& lexical_region() const override { return *lexreg; }
};