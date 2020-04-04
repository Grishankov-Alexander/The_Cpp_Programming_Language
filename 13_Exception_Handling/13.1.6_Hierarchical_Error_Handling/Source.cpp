void callC()  // call a C function from C++, convert errno to throw
{
	errno = 0;
	c_function();
	if (errno) {
		// ... local cleanup, if possible and necessary
		throw C_blewit(errno);
	}
}

extern "C" void call_from_C() noexcept  // call a C++ function from C, convert a throw to errno
{
	try {
		c_plus_plus_function();
	}
	catch (...) {
		// ... local cleanup
		errno = E_CPLPLFCTBLEWIT;
	}
}