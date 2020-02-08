#pragma once

#include <string>
#include <vector>
#include <sstream>
#include <unordered_map>

#include "Utilities/Math/Math.h"

namespace MxEngine
{
	struct MaterialInfo
	{
		std::string map_Ka;
		std::string map_Kd;
		std::string map_Ks;
		std::string map_Ke;
		std::string map_d;
		std::string map_bump;
		std::string bump;

		float Ns = 0.0f;
		float Ni = 0.0f;
		float d = 0.0f;
		float Tr = 0.0f;
		float bm = 0.0f;
		Vector3 Tf{ 0.0f };
		Vector3 Ka{ 0.0f };
		Vector3 Kd{ 0.0f };
		Vector3 Ks{ 0.0f };
		Vector3 Ke{ 0.0f };
		int illum = 0;
		bool IsSuccess = true;
	};

	struct GroupInfo
	{
		std::string name;
		std::vector<float> buffer;
		std::vector<Vector<3, long long>> faces;		
		MaterialInfo* material = nullptr;
		bool useTexture = false;
		bool useNormal = false;
	};

	using MaterialLibrary = std::unordered_map<std::string, MaterialInfo>;

	struct ObjFileInfo
	{
		MaterialLibrary materials;
		std::vector<GroupInfo> groups;
        Vector3 objectCenter = { 0, 0, 0 };
		size_t lineCount = 0;
		bool isSuccess = true;
	};

	class ObjectLoader
	{
		static void ReadFace(std::stringstream& file, ObjFileInfo& obj);
		static MaterialLibrary LoadMaterialLibrary(const std::string& path);
		static MaterialInfo LoadMaterial(std::stringstream& file);
	public:
		static ObjFileInfo Load(const std::string& path);
	};
}