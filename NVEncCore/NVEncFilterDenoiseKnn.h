﻿// -----------------------------------------------------------------------------------------
// NVEnc by rigaya
// -----------------------------------------------------------------------------------------
//
// The MIT License
//
// Copyright (c) 2014-2016 rigaya
//
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in
// all copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
// THE SOFTWARE.
//
// ------------------------------------------------------------------------------------------

#pragma once

#include "NVEncFilter.h"
#include "NVEncParam.h"
#include "logo.h"

class NVEncFilterParamDenoiseKnn : public NVEncFilterParam {
public:
    VppKnn knn;

    NVEncFilterParamDenoiseKnn() : knn() {

    };
    virtual ~NVEncFilterParamDenoiseKnn() {};
};

class NVEncFilterDenoiseKnn : public NVEncFilter {
public:
    NVEncFilterDenoiseKnn();
    virtual ~NVEncFilterDenoiseKnn();
    virtual NVENCSTATUS init(shared_ptr<NVEncFilterParam> pParam, shared_ptr<CNVEncLog> pPrintMes) override;
protected:
    virtual NVENCSTATUS run_filter(const FrameInfo *pInputFrame, FrameInfo **ppOutputFrames, int *pOutputFrameNum) override;
    virtual void close() override;

    NVENCSTATUS denoiseYV12(FrameInfo *pOutputFrame, const FrameInfo *pInputFrame);
    NVENCSTATUS denoiseYUV444(FrameInfo *pOutputFrame, const FrameInfo *pInputFrame);

    bool m_bInterlacedWarn;
};