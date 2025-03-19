#pragma once
class CGameFramework
{
public:
	CGameFramework();
	~CGameFramework();

	IDXGIFactory4* m_pdxgiFactory;
	IDXGISwapChain3* m_pdxgiSwapChain;
	ID3D12Device* m_pd3dDevice;

	bool m_bM;

};

