#pragma once
#ifndef _MODELCLASS_H_
#define _MODELCLASS_H_

#include <d3d11.h>
#include <d3dx10math.h>
#include <fstream>
#include "textureclass.h"
using namespace std;

class ModelClass {
private:
	struct VertexType {
		D3DXVECTOR3 position;
		//D3DXVECTOR4 color;
		D3DXVECTOR2 texture;
		D3DXVECTOR3 normal;
	};
	struct ModelType {
		float x, y, z;
		float tu, tv;
		float nx, ny, nz;
	};
public:
	ModelClass();
	ModelClass(const ModelClass&);
	~ModelClass();

	//bool Initialize(ID3D11Device*, const char*);
	bool Initialize(ID3D11Device*, char*, const char*);
	void Shutdown();
	void Render(ID3D11DeviceContext*);
	int GetIndexCount();
	ID3D11ShaderResourceView* GetTexture();
private:
	bool InitializeBuffers(ID3D11Device*);
	void ShutdownBuffers();
	void RenderBuffers(ID3D11DeviceContext*);
	bool LoadTexture(ID3D11Device*, const char*);
	void ReleaseTexture();
	bool LoadModel(const char*);
	void ReleaseModel();
private:
	ID3D11Buffer * m_vertexBuffer, *m_indexBuffer;
	int m_vertexCount, m_indexCount;
	TextureClass* m_Texture;
	ModelType* m_model;
};

#endif




























