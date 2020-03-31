struct Some_error {};
int do_task()
{
	if ( /*could perform the task*/)
		return result;
	else throw Some_error{};
}
void taskmaster()
{
	try {
		auto result = do_task();
	}
	catch (Some_error) {
		// failure to do_task: handle problem
	}
}