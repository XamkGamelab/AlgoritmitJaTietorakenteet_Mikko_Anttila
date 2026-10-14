#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdio>
#include "stack.h"
#include <string>


bool IsVoidElement(const std::string& tag)
{
	return tag == "<area>" || tag == "<base>" || tag == "<br>" || tag == "<col>" || tag == "<embed>" || tag == "<hr>" || tag == "<img>" || tag == "<input>" || tag == "<link>" ||
		tag == "<meta>" || tag == "<param>" || tag == "<source>" || tag == "<track>" || tag == "<wbr>";
}

int main (int argc, char** argv)
{
	if (argc >= 2) {
		std::cout << "Called: " << argv[0] << " " << argv[1] << "\n";

		FILE* fp = nullptr;
		errno_t error = fopen_s(&fp, argv[1], "r");

		if (fp == NULL) {
			std::cout << "Failed to open file: " << argv[1] << "\n";
			return EXIT_FAILURE;
		}

		char c;
		char cc;
		std::string line;
		Stack<std::string> lines;
		Stack<int> linesPosition;
		Stack<std::string> mismatchedLines;
		Stack<int> mismatchedLinesPosition;
		bool opened = false;
		bool closingLine = false;
		int linedownCount = 1;

		while ((c = std::fgetc(fp)) != EOF)
		{
			std::cout << c;
			if (c == '\n') linedownCount++;

			if (c == '<' || opened)
			{
				if (c == '<')
				{
					opened = true;
					closingLine = false;
					line = "<";
				}
				else if (opened && c == '/')
				{
					closingLine = true;
				}
				else if (opened && c != '>' && c != ' ')
				{
					line += c;
				}

				if (c == ' ' || c == '>')
				{
					line += '>';
					if (closingLine) {
						if (!lines.IsEmpty() && lines.Top() == line)
						{
							lines.Pop();
							linesPosition.Pop();
							closingLine = false;
							opened = false;
							line.clear();
						}
						else{
							while (!lines.IsEmpty() && lines.Top() != line)
							{
								mismatchedLines.Push(lines.Top());
								mismatchedLinesPosition.Push(linesPosition.Top());
								lines.Pop();
								linesPosition.Pop();
							}

							if (!lines.IsEmpty()) {
								lines.Pop();
								linesPosition.Pop();
							}
							closingLine = false;
							opened = false;
							line.clear();
						}
					}
					else
					{
						closingLine = false;
						opened = false;
						if (!IsVoidElement(line)) {
							lines.Push(line);
							linesPosition.Push(linedownCount);
						}
						line.clear();
					}
				}
			}
		}

		while (!lines.IsEmpty())
		{
			mismatchedLines.Push(lines.Top());
			mismatchedLinesPosition.Push(linesPosition.Top());
			lines.Pop();
			linesPosition.Pop();
		}

		std::cout << "\n\n" << "Tags that weren't closed: \n";
		if (mismatchedLines.IsEmpty()) {
			std::cout << "No unclosed tags!\n";
		}
		else {
			while (!mismatchedLines.IsEmpty())
			{
				std::cout << mismatchedLines.Top() << " (line " << mismatchedLinesPosition.Top() << ")\n";
				mismatchedLines.Pop();
				mismatchedLinesPosition.Pop();
			}
		}

		std::fclose(fp);
		return EXIT_SUCCESS;
	}
	else {
		std::cout << "Missing Arguments, Called: " << argv[0] << "\n";
		return EXIT_FAILURE;
	}
}