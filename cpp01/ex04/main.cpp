/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akrepkov <akrepkov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 15:22:10 by akrepkov          #+#    #+#             */
/*   Updated: 2024/03/17 12:59:45 by akrepkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>
#include <fstream>

int main(int argc, char *argv[]){
	std::string newLine;
	if (argc != 4){
		std::cerr << "Wrong amount" <<
			" of arguments" << std:: endl; //if the line is too long, delete before pushing
		return 1;
	}
	std::string infile = argv[1];
	std::ifstream inputFile(infile.c_str()); // Convert infile to const char*
	if (!inputFile){
		std::cerr << "Couldn't read the input" << std:: endl;
		return 1;
	}
	std::string outfile = infile + ".replace";
	std::ofstream outputFile(outfile.c_str());
	if (!outputFile){
		std::cerr << "Couldn'r create the output" << std:: endl;
		return 1;
	}
	std::string s1 = argv[2];
	std::string s2 = argv[3];
	std::string line;
	while(getline(inputFile, line)){
		size_t pos = line.find(s1);
		while (pos != std::string::npos){ // means "until the end of the string"
			line = line.substr(0, pos) + s2 + line.substr(pos + s1.length());
			pos++;
			pos = line.find(s1, pos + s1.length());
		}
		outputFile << line << std::endl;

	}
	outputFile.close();
	inputFile.close();
	return 0;
}

/*   функция ignore() — игнорирует первый символ из потока;

   функция ignore(int nCount) — игнорирует первые nCount (количество) символов из потока;

   функция peek() — считывает символ из потока, при этом не удаляя его из потока;

   функция unget() — возвращает последний считанный символ обратно в поток, чтобы его можно было извлечь в следующий раз;

   функция putback(char ch) — помещает выбранный вами символ обратно в поток, чтобы его можно было извлечь в следующий раз.*/
   