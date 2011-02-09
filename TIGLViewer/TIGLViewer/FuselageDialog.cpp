/* 
* Copyright (C) 2007-2011 German Aerospace Center (DLR/SC)
*
* Created: 2010-08-13 Markus Litz <Markus.Litz@dlr.de>
* Changed: $Id: FuselageDialog.cpp 4416 2011-02-08 21:03:40Z litz_ma $ 
*
* Version: $Revision: 4416 $
*
* Licensed under the Apache License, Version 2.0 (the "License");
* you may not use this file except in compliance with the License.
* You may obtain a copy of the License at
*
*     http://www.apache.org/licenses/LICENSE-2.0
*
* Unless required by applicable law or agreed to in writing, software
* distributed under the License is distributed on an "AS IS" BASIS,
* WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
* See the License for the specific language governing permissions and
* limitations under the License.
*/

#include "stdafx.h"
#include "TIGLViewer.h"
#include "FuselageDialog.h"
#include "CCPACSFuselage.h"
#include "TIGLViewerDoc.h"
#include "CCPACSConfiguration.h"
#include ".\fuselagedialog.h"

IMPLEMENT_DYNAMIC(CFuselageDialog, CDialog)

BEGIN_MESSAGE_MAP(CFuselageDialog, CDialog)
	ON_LBN_SELCHANGE(IDC_FUSELAGE_LIST, OnLbnSelchangeFuselageList)
END_MESSAGE_MAP()

CFuselageDialog::CFuselageDialog(CTIGLViewerDoc& document)
	: CDialog(CFuselageDialog::IDD, 0)
	, m_document(document)
{
}

CFuselageDialog::~CFuselageDialog()
{
}

void CFuselageDialog::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_FUSELAGE_LIST, m_fuselageList);
}

int CFuselageDialog::GetFuselageIndex(void) const
{
    return index;
}

std::string CFuselageDialog::GetFuselageName(void) const
{
    return fuselageName;
}

void CFuselageDialog::OnOK()
{
	CString strTemp;
	UpdateData(TRUE);
	index = m_fuselageList.GetCurSel();
	m_fuselageList.GetText(index, strTemp);
	fuselageName = (char*)(LPCSTR)strTemp; 
    CDialog::OnOK();
}

BOOL CFuselageDialog::OnInitDialog()
{
	CDialog::OnInitDialog();

	// Initialize wing list
	tigl::CCPACSConfiguration& config = m_document.GetConfiguration();
	int fuselageCount = config.GetFuselageCount();
	for (int i = 1; i <= fuselageCount; i++) 
	{
		tigl::CCPACSFuselage& fuselage = config.GetFuselage(i);
		std::string name = fuselage.GetName();
		if (name == "") name = "Unknown fuselage";
		m_fuselageList.InsertString(i - 1, _T(name.c_str()));
	}
	return TRUE;  // return TRUE unless you set the focus to a control
}

void CFuselageDialog::OnLbnSelchangeFuselageList()
{
	// TODO: F�gen Sie hier Ihren Kontrollbehandlungscode f�r die Benachrichtigung ein.
}
