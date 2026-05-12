# CPP Module 05

Module 05 focuses on **exceptions**, **invariants**, **abstract base classes**, and **object creation through a common interface**.

## ex00: Bureaucrat

Build a `Bureaucrat` class with:

- a **const name**
- a **grade** limited to `1..150`

Main ideas:

- **class invariants**
- **bounds checking**
- **custom exceptions**
- **nested exception classes**
- `try` / `catch`
- `operator<<`

A bureaucrat must never exist in an invalid state.  
Invalid construction or invalid grade changes must throw.

## ex01: Form up, maggots!

Add a `Form` class with:

- a **const name**
- a **signed / unsigned state**
- a **const grade required to sign**
- a **const grade required to execute**

Main ideas:

- expansion of **exceptions + invariants**
- **inter-object collaboration**
- **delegation**
- signing workflow between classes

Key relation:

- `Bureaucrat::signForm()` tries to sign
- `Form::beSigned()` decides whether signing is allowed

The important design idea is that the object that owns the rule should enforce it.

## ex02: No, you need form 28B, not 28C...

Turn `Form` into **`AForm`**, an **abstract base class**, and add concrete derived forms:

- `ShrubberyCreationForm`
- `RobotomyRequestForm`
- `PresidentialPardonForm`

Main ideas:

- **abstract class**
- **inheritance**
- **runtime polymorphism**
- **execution preconditions**
- concrete behavior in subclasses

A form must not execute unless:

- it is **signed**
- the executor has a **high enough grade**

Each derived form defines its own action.

## ex03: At least this beats coffee-making

Implement the `Intern` class.

The intern has no meaningful state.  
Its only important job is:

- `makeForm(formName, target)`

Main ideas:

- **factory-style creation**
- choosing a concrete subclass from runtime input
- returning it through a common base pointer: `AForm*`
- clean dispatch logic

`makeForm()` should:

- receive the form name and target
- create the matching concrete form
- print `Intern creates <form>`
- print an explicit error message if the form name is unknown

This exercise is about creating the right object from a string without messy branching.
