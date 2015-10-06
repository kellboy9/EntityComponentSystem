Testing out the Entity/Component System design pattern using C and SDL2.

Objects will all theoretically be the same entity type, but with different components that will have actions performed on them by systems.
Not really OOP, but similar in practice (not in theory)

Objects are defined not nominally, but, rather, by a system of components. In theory each system will act on an individual set of components, rather than having to check for types and classes of whatever data gets passed to them.
