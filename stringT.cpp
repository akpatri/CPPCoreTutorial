// Declaration
// Following is the declaration for std::string.

// typedef basic_string<char> string;
// C++11
// typedef basic_string<char> string;
// Member types
// member type	definition
// value_type	char
// traits_type	char_traits<char>
// allocator_type	allocator<char>
// reference	char&
// const_reference	const char&
// pointer	char*
// const_pointer	const char*
// iterator	a random access iterator to char (convertible to const_iterator)
// const_iterator	a random access iterator to const char
// reverse_iterator	reverse_iterator<iterator>
// const_reverse_iterator	reverse_iterator<const_iterator>
// difference_type	ptrdiff_t
// size_type	size_t
// Member functions
// S.N.	Member function & description
// 1	(constructor)
// It constructs string object.

// 2	(destructor)
// It is a string destructor.

// 3	operator=
// It is a string assignment.

// Iterators
// S.N.	Iterator & description
// 1	begin
// It returns iterator to beginning.

// 2	end
// It returns iterator to end.

// 3	rbegin
// It returns reverse iterator to reverse beginning.

// 4	rend
// It returns reverse iterator to reverse end.

// 5	cbegin
// It returns const_iterator to beginning.

// 6	cend
// It returns a const_iterator pointing to the past-the-end character of the string.

// 7	crbegin
// It returns const_reverse_iterator to reverse beginning.

// 8	crend
// It returns const_reverse_iterator to reverse end.

// Capacity
// S.N.	Capacity & description
// 1	size
// It returns length of string.

// 2	length
// It returns length of string.

// 3	max_size
// It returns maximum size of string.

// 4	resize
// It resizes string.

// 5	capacity
// It returns size of allocated storage.

// 6	reserve
// It requests a change in capacity.

// 7	clear
// It clears the string.

// 8	empty
// It is used to test if string is empty.

// 9	shrink_to_fit
// It is used to shrink to fit.

// Capacity
// S.N.	Element acce & description
// 1	operator[]
// It is used to get character of string.

// 2	at
// It is used to get character in string.

// 3	back
// It is used to access last character.

// 4	front
// It is used to access first character.

// Modifiers
// S.N.	Modifier & description
// 1	operator+=
// It appends to string.

// 2	append
// It appends to string.

// 3	push_back
// It appends a character to string.

// 4	assign
// It is used to assign the content to string.

// 5	insert
// It is used to inset the value to string.

// 6	erase
// It is used to erase characters from string.

// 7	replace
// It is used to replace portion of string.

// 8	swap
// It is used to swap string values.

// 9	pop_back
// It is used to delete last character.

// String operations
// S.N.	String operation & description
// 1	c_str
// It is used to get C string equivalent.

// 2	data
// It is used to get string data.

// 3	get_allocator
// It is used to get an allocator.

// 4	copy
// It is used to copy sequence of characters from string.

// 5	find
// It is used to find content in string.

// 6	rfind
// It is used to find last occurrence of content in string.

// 7	find_first_of
// It is used to find character in string.

// 8	find_last_of
// It is used to find character in string from the end.

// 9	find_first_not_of
// It is used to find absence of character in string.

// 10	find_last_not_of
// It is used to find non-matching character in string from the end.

// 11	substr
// It is used to generate substring.

// 12	compare
// It is used to compare strings.