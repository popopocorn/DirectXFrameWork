#include "Scene.h"
#include"stdafx.h"
CScene::CScene() {

}

bool OnProcessingMouseMessage(HWND hWnd, UINT nMessageID, WPARAM wParam, LPARAM lParam);
bool OnProcessingKeyboardMessage(HWND hWnd, UINT nMessageID, WPARAM wParam, LPARAM lParam);

void CScene::CreateGraphicsRootSignature(ID3D12Device* pd3dDevice) {
	D3D12_ROOT_SIGNATURE_DESC d3dRootSignatureDesc;
	::ZeroMemory(&d3dRootSignatureDesc, sizeof(D3D12_ROOT_SIGNATURE_DESC));
	d3dRootSignatureDesc.NumParameters = 0;
	d3dRootSignatureDesc.pParameters = NULL;
	d3dRootSignatureDesc.NumStaticSamplers = 0;

	d3dRootSignatureDesc.pStaticSamplers = NULL;
	d3dRootSignatureDesc.Flags =
		D3D12_ROOT_SIGNATURE_FLAG_ALLOW_INPUT_ASSEMBLER_INPUT_LAYOUT;

	ID3DBlob* pd3dSignatureBlob = NULL;
	ID3DBlob* pd3dErrorBlob = NULL;
	::D3D12SerializeRootSignature(&d3dRootSignatureDesc, D3D_ROOT_SIGNATURE_VERSION_1,
		&pd3dSignatureBlob, &pd3dErrorBlob);
	pd3dDevice->CreateRootSignature(0, pd3dSignatureBlob->GetBufferPointer(),
		pd3dSignatureBlob->GetBufferSize(), __uuidof(ID3D12RootSignature), (void**)&m_pd3dGraphicsRootSignature);
	//여기부터 다시
}
void CreateGraphicsPipeLineState(ID3D12Device* pd3dDevice);

void BuildObjects(ID3D12Device* pd3dDevice);
void ReleaseObjects();

bool ProcessInput();
void AnimateObjects(float fTimeElapsed);

void PrepareRender(ID3D12GraphicsCommandList* pd3dCommandList);
void Render(ID3D12GraphicsCommandList* pd3dCommandList);

ID3D12RootSignature* m_pd3dGraphicsRootSignature = NULL;

ID3D12PipelineState* m_pd3dPipelineState = NULL;
};

