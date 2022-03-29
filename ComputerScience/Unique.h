#pragma once
#include <string>
#include <map>
#include <algorithm>

//version crade
bool isUniqueCrade(std::string word) {
	if (word.size() != 1) {
		for (int i = 0; i < word.size(); i++) {
			for (int j = 0; j < word.size(); j++) {
				if (i == j) {
					continue;
				}else {
					if (word[i] == word[j]) {
						return false;
					}
				}
			}
		}
	}
	return true;
}

//version avec map
bool isUniqueMap(std::string word) {
	if (word.size() != 1) {
		std::map<char, int> wordMap;
		for (int i = 0; i < word.size(); i++) {
			auto it = wordMap.find(word[i]);
			if (it != wordMap.end()) {
				return false;
			}
			else {
				wordMap.insert({ word[i], i });
			}
		}
	}
	return true;
}

// version avec organize
bool isUniqueOrganize(std::string& word) {
	std::sort(word.begin(), word.end());
	for (int i = 0; i < word.size() - 1; i++) {
		if (word[i] == word[i + 1]) {
			return false;
		}
	}
	return true;
}

////version correction
//bool isUnique(std::string s) {
//	if (s.length() > 128 || s.length) return false;
//
//	boolean[] set = new boolean[128];
//	for (int i = 0; i < s.length(); i++) {
//		int v = s.charAt(i);
//		if (set[v]) {
//			return false;
//		}
//		set[v] = true;
//	}
//	return true;
//}