Dynamic init demo
=================

This esp-idf project is intended as a quick demo on how to use object sections
for simple, dynamic init systems.

When initializing a set of components in C there is either a variable somewhere
containing a list of all components that need to initialized or all init
functions are called in appropriate order in some code section.

However, theese lists need to be maintained. Whenever a new component is added
they need to be extended.


This additional management overhead can be avoided by using dynamic
initialization based on object sections.

The basic concept of this method is to store function pointers for
initalization of components in a dedicated section of object files using
the gcc section("sectionname") attribute. By emitting start and stop symbols
for this section at the linking stage theese sections can be referenced in C
code and iterated.

Since the sections are dynamically aggregated at link time over all objects in
the link the section will then contain an unordered list of all initialization
function pointers in the program.

If special ordering is desired multiple sections can be created.
