# passiveBandpass
TFE17-2 informatics task 3 (November 26, 2018)
Solution by Maximilian Bachmann, Felix Bandle, Florian Vetter

Last submission date: Dezember 09, 2018

##Required functions:

| function | description |
|-------------|-------------|
|`Vector(size_t size)`| constructs a vector with a specific size|
|`Vector(const Vector& a)`| constructs a copied vector|
|`value_type& at(size_t pos)`|Returns a copy of the item at the wanted position, when it exists. When the position is out of range, it throws an exeption.|
|`void push_back(const value_type& value)`|Adds a item at the end of the vector.|
|`void push_back(value_type& value)`|Adds a item at the end of the vector.|
|`void push_back_slow(const value_type& value)`|Adds a item at the end of the vector with size = capacity.|
|`void push_back_slow(value_type& value)`|Adds a item at the end of the vector with size = capacity.|
|`void pop_back()`|Deletes the last item of the vector.|
|`void pop_back_slow()`|Deletes the last item of the vector with size = capacity.|
|`size_t size() const`|Returns the size of a vector.|
|`size_t capacity() const`|Returns the capacity of a vector.|
|`void resize(int size)`|Resizes the vector.|
|`void clear()`|Clears all items of a vector.|
|`Vector& operator= (const Vector& x)`|custom assignment operator to make a deep copy of a Vector.|
|`value_type& operator[] (size_t index)`|Getting access on a specific item for write and read.|
|`const value_type& operator[] (size_t index) const`|Getting access on a specific item for read.|

