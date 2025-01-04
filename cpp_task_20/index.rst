.. _makefile_usage:

Using the Makefile
==================

This section explains how to use the provided Makefile to build, run, and clean your project.

Building the Project
--------------------

To build the project, run the following command in your terminal:

.. code-block:: sh

	make

This command will create the `build` directory, run CMake to generate the necessary build files, and then compile the project.

Running the Executable
----------------------

To run the compiled executable, use the following command:

.. code-block:: sh

	make run

This command will build the project (if it hasn't been built yet) and then execute the `my_boost_filesystem` binary.

Cleaning Up
-----------

To clean up the generated files and directories, use the following command:

.. code-block:: sh

	make clean

This command will remove the `build` directory and all its contents.
