#include <vector>
#pragma once

using namespace std;

namespace logic {
    void Update();
	void AddObj(int x, int y, vector<string> sprite);
	struct ScreenObject;
	vector<ScreenObject> GetList();
}
namespace renderer {
	void Update();
}