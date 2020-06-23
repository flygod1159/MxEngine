#pragma once

#include <MxEngine.h>
#include "UserObjects.h"
#include <Library/Primitives/Primitives.h>

using namespace MxEngine;

class SandboxScene
{
public:
    void OnCreate()
    {
		auto cube = MxObject::Create();
		InitCube(*cube);
		
		auto sphere = MxObject::Create();
		InitSphere(*sphere);
		
		auto grid = MxObject::Create();
		InitGrid(*grid);
		
		auto surface = MxObject::Create();
		InitSurface(*surface);

        //auto arc = MxObject::Create();
		//InitArc(*arc);
		//arc.MakeStatic();

		// auto& deathStar = this->AddObject("DeathStar", MakeUnique<MxObject>());
		// InitDeathStar(deathStar);

		// auto& destroyer = this->AddObject("Destroyer", MakeUnique<MxObject>());
		// InitDestroyer(destroyer);

		// auto object = MxObject::Create();
		// object->AddComponent<MeshSource>(AssetManager::LoadMesh("D:/repos/glTF-Sample-Models/2.0/Sponza/glTF/Sponza.gltf"));

		Script initScript(FileManager::GetFilePath("scripts/init.py"_id));
        Application::Get()->ExecuteScript(initScript);
		
		auto dirLight = MxObject::Create();
		InitDirLight(*dirLight);

		auto pointLight = MxObject::Create();
		InitPointLight(*pointLight);
		
		auto spotLight = MxObject::Create();
		InitSpotLight(*spotLight);

		auto camera = MxObject::Create();
		InitCamera(*camera);

		// TODO: add debug draw component 
		// TODO: move LOD compute logic to MeshLOD component
		// TODO: runtime editor settings
		// TODO: remove AABB from MxObject
		// TODO: update readme

		RenderManager::SetViewport(camera->GetComponent<CameraController>());
    }

	void OnUpdate()
	{
	}
};