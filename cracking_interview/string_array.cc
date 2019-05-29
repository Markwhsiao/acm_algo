#include <iostream>
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <cstring>
#include <algorithm>
bool IsUniqString(const char* str) {
  uint8_t char_bit_map[32] = {0};
  char* b = const_cast<char*>(str);
  while (*b != '\0'){
  	uint8_t i = (*b) >> 3;
  	uint8_t mask = (0x80) >> ((*b) & 0x7);
  	if ((char_bit_map[i] & mask) != 0){
  	  return false;
	}
	char_bit_map[i] |= mask;
	b ++;
  }
  return true;
}

char* ReverseString(char* str) {
  char* bgn = str;
  char* end = str + strlen(str) - 1;
  while(bgn < end) {
  	char c = *bgn;
  	*bgn = *end;
  	*end = c;
	bgn ++;
  	end --;
  }
  return str;
}
//TODO: error
char* RemoveDuplicateChar2(char* str) {
  if (strlen(str) <= 1) {
  	return str;
  }
  char* src = str;
  char* dst = str + 1;
  while(1) {
  	while (*dst != '\0' && *dst == *src) {
	  dst ++;
	}
  	src ++;
	*src = *dst;
	if (*dst == '\0') {
	  break;
	} 
	dst ++;
  }
  return str;
}
// 这个实现还是蛮好的 
char * RemoveDuplicateChar(char*str) {
	if (strlen(str) <= 1) {
		return str;
	}
	int len = strlen(str);
	int tail = 1;
	for(int j = 1; j < len; ++j) {
		int i;
		for(i = 0; i < tail; ++ i) {
			if (str[i] == str[j]) {
				break;
			}
		}
		if (i == tail) {
			// j与str[0~tail] 无重复
			str[tail] = str[j];
			 ++ tail; 
		}
	}
	str[tail] = '\0';
	return str;
}

bool Anagrams(char* a, char *b) {
  char* a_end = a + strlen(a);
  char* b_end = b + strlen(b);
  std::sort(a, a_end);
  std::sort(b, b_end);
  printf("a=%s, b=%s\n", a, b);
  return strcmp(a, b) == 0;
}

char* ReplaceEmpty(char* str, char* result) {
  char* bgn = str;
  char* dst = result;
  while(*bgn != '\0') {
  	if (*bgn == ' ') {
  		*dst ++ = '%';
  		*dst ++ = '2';
  		*dst ++ = '0';
	} else {
		*dst = *bgn;
		dst ++;
	}
	bgn ++; 
  }
  *dst = '\0';
  return result; 	
}

void RotateImage90(uint32_t* pixer_array, uint32_t dim) {
	for(uint32_t i = 0; i < dim; ++ i) {
		for (uint32_t j = i + 1; j < dim; ++ j) {
			uint32_t tmp = pixer_array[i*dim + j];
			pixer_array[i*dim + j] = pixer_array[j*dim + i];
			pixer_array[j*dim + i] = tmp;
		}
	}
}

void SetZero(uint32_t* pixer_array, uint32_t row, uint32_t col) {
	uint8_t* r = new uint8_t[row];
	uint8_t* c = new uint8_t[col];
	memset(r, 0, row);
	memset(c, 0, col);

	for(uint32_t i = 0; i < row; ++ i) {
		if (r[i]) continue;
		for (uint32_t j = 0; j < col; ++ j) {
			if(c[j]) continue;
			if (pixer_array[i*col + j] == 0) {
				for(uint32_t k = 0; k < col; ++k) {
					pixer_array[i*col + k] = 0;
				}
				for(uint32_t l = 0; l < row; ++l) {
					pixer_array[l*col + j] = 0;
				}
				r[i] = true;
				c[j] = true;
				break;
			}
			
		}
	}
	delete r;
	delete c;
} 

bool IsRotate(char* a, char* b) {
	uint32_t la = strlen(a);
	uint32_t lb = strlen(b);
	if (la != lb) {
		return false;
	} else if (la == 1) {
		return *a == *b;
	}
	
	char* tmp = new char[la + la + 1];
	strncpy(tmp, a, la);
	strncpy(tmp + la, a, la);
	*(tmp + la + la) = '\0';
	bool is_rotate = strstr(tmp, b) != nullptr;
	delete[] tmp;
	return is_rotate;	
}

int main(int argc, char** argv) {
	
	std::cout << "ISuniqString(Hello) return " << IsUniqString("hello") << std::endl;
	std::cout << "ISuniqString(world) return " << IsUniqString("world") << std::endl;
	char buf[256] = "Hello";
	std::cout << "ReverseString(Hello) return " << ReverseString(buf) << std::endl;
	char buf2[256] = "HeollH";
    std::cout << "RemoveDuplicateChar(HeollH) return " << RemoveDuplicateChar(buf2) << std::endl;
	char buf3[256] = "Heoll";	
	std::cout << "Anagrams(Hello, Heoll) return " << Anagrams(buf, buf3) << std::endl;
	
	char buf4[256] = "abcdefg aa 78/";
	char result[256];
	std::cout << "ReplaceEmpty(abcdefg aa 78/) = " << ReplaceEmpty(buf4, result) << std::endl;
	
	uint32_t pixer_array[9] = {1,2,3,4,5,6,7,8,9};
	RotateImage90(pixer_array, 3);
	for(uint32_t i = 0; i < 3; ++i) {
		for(uint32_t j = 0; j < 3; ++j) {
			std::cout << pixer_array[i*3 + j] << ",";
		}
		std::cout << std::endl;
	}
	
	
	uint32_t pixer_array2[6] = {0,2,3,4,1,6};
	SetZero(pixer_array2, 2, 3);
	for(uint32_t i = 0; i < 2; ++i) {
		for(uint32_t j = 0; j < 3; ++j) {
			std::cout << pixer_array2[i*3 + j] << ",";
		}
		std::cout << std::endl;
	}
	
	
	std::cout << "IsRotate(waterbottle, bottlewater) return " << IsRotate("waterbottle", "bottlewater") << std::endl;
	
	std::cout << "IsRotate(waterbottle, bottlewater) return " << IsRotate("waterbottle", "bottleawter") << std::endl;
	
	system("pause");
	return 0;
}
