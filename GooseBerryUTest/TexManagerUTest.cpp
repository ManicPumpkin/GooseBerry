#pragma comment(lib, "GooseBerry.lib")

#include "stdafx.h"
#include "CppUnitTest.h"
#include "gooseberry.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace GooseBerryUTest
{
	TEST_MODULE_INITIALIZE(ModuleInitialize)
	{
		Logger::WriteMessage("Initialize TexManagerClass");
	}

	TEST_MODULE_CLEANUP(ModuleCleanup)
	{
		Logger::WriteMessage("CleanUp TexManagerClass");
	}

	TEST_CLASS(TexManagerUTestClass)
	{
		private:
			const char * tex_name_ = ".\\dta\\pumpkin_64x64_black.jpg";

			int ToInt(gbResult value)
			{
				switch (value)
				{
				case GB_OK: return 0;
				case GB_ERROR: return 1;
				case GB_NOTFOUND: return 2;
				case GB_STOP: return 3;
				default: return -1;
				}
			}

		public:
		
			TEST_METHOD(TManagerAddOneTex)
			{
				Logger::WriteMessage("--> [Test] Add one texture");
				int tex_nr;
				gbResult result = TEXMANAGER->LoadTexture(tex_name_, &tex_nr);
				Assert::AreEqual(ToInt(result), ToInt(GB_OK));

				TEXMANAGER->RemoveAllTextures();
			}

			TEST_METHOD(TManagerExtendQueue)
			{
				Logger::WriteMessage("--> [Test] Extend queue");
				int tex_nrs[24];
				gbResult result;

				for (int i = 1; i <= 8; i++)
				{
					result = TEXMANAGER->LoadTexture(tex_name_, &tex_nrs[i]);
					Assert::AreEqual(ToInt(result), ToInt(GB_OK));
				}

				int num_tex = TEXMANAGER->GetNumTextures();
				Assert::AreEqual(8, num_tex);
				Assert::AreEqual(16, TEXMANAGER->GetAvailableSpace());

				for (int i = num_tex; i < num_tex + 10; i++)
				{
					result = TEXMANAGER->LoadTexture(tex_name_, &tex_nrs[i]);
					Assert::AreEqual(ToInt(result), ToInt(GB_OK));
				}

				num_tex = TEXMANAGER->GetNumTextures();
				Assert::AreEqual(18, num_tex);
				Assert::AreEqual(24, TEXMANAGER->GetAvailableSpace());

				TEXMANAGER->RemoveAllTextures();
			}

			TEST_METHOD(TManagerRemoveTwoTex)
			{
				Logger::WriteMessage("--> [Test] Remove two textures from queue");
				int tex_nrs[8];
				for (int i = 0; i < 8; i++)
					 TEXMANAGER->LoadTexture(tex_name_, &tex_nrs[i]);
				Assert::AreEqual(8, TEXMANAGER->GetNumTextures());

				int id	= TEXMANAGER->GetTexId(1);
				TEXMANAGER->RemoveTextureById(id);
				Assert::AreEqual(7, TEXMANAGER->GetNumTextures());

				TEXMANAGER->RemoveTextureByIndex(2);
				Assert::AreEqual(6, TEXMANAGER->GetNumTextures());

				TEXMANAGER->RemoveAllTextures();
			}

			TEST_METHOD(TManagerRemoveAllTex)
			{
				Logger::WriteMessage("--> [Test] Remove all textures from queue");
				int tex_nrs[4];
				for (int i = 0; i < 4; i++)
					TEXMANAGER->LoadTexture(tex_name_, &tex_nrs[i]);
				Assert::AreEqual(4, TEXMANAGER->GetNumTextures());

				TEXMANAGER->RemoveAllTextures();
				Assert::AreEqual(0, TEXMANAGER->GetNumTextures());

				TEXMANAGER->RemoveAllTextures();
			}
	};
}