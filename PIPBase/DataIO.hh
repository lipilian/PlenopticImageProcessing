/**
 * Copyright 2019 Arne Petersen, Kiel University
 *
 *    Permission is hereby granted, free of charge, to any person obtaining a copy of this software and 
 *    associated documentation files (the "Software"), to deal in the Software without restriction, including
 *    without limitation the rights to use, copy, modify, merge, publish, distribute, sublicense, and/or 
 *    sell copies of the Software, and to permit persons to whom the Software is furnished to do so, subject
 *    to the following conditions:
 *
 *    The above copyright notice and this permission notice shall be included in all copies or substantial
 *    portions of the Software.
 *
 *    THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT
 *    LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN
 *    NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY,
 *    WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE
 *    SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.#pragma once
 */

#pragma once

#include "CVImage.hh"
#include "PlenopticTypes.hh"

namespace PIP
{

class CDataIO
{
public:
    ///
    /// \brief ImportImage tries to import an image from given file.
    /// \param img import target
    /// \param strFilename file to read
    /// \param flagReformat true to convert to standard
    ///
    /// Convert to standard format : OpenCV reads images in BGR[A] color model. Use 'flagReformat' to force
    /// conversion to RGBA for all (including mono) images. This is recomennded for color images since CUDA
    /// cannot use  3-channel textures.
    ///
    /// Bayer-patterns are not accounted for. If the image is known to be of bayer type, use debayering
    /// method seperately.
    ///
    /// Allowed formats are png, pbm, ppm, tiff, openexr, jpg (providing capability of bound opencv modules)
    ///
    /// Since the original image type (depthmap, float array...) cannot be determined from image, it has be
    /// set manually (if it differs from MOMO/RGB/RGBA) after import.
    ///
    static void ImportImage(CVImage& img, const std::string strFilename, const bool flagReformat = false);
    
    static void ExportImage(const CVImage& img, const std::string strFilename);

    static void DebayerImage(CVImage& imgColor, const CVImage& imgBayer, const EImageType eBayerType);

    static void ImageToRGBA(CVImage& imgRGBA, const CVImage& imgAnyType);

    ///
    /// \brief ExportToASCII write a channel of an image to an ASCII file
    /// \param img
    /// \param strFilename
    /// \param intChannel
    ///
    static void ExportToASCII(const CVImage& img, const std::string &strFilename, const int intChannel = 0);
    
protected:
    // Static only
    CDataIO() {}
};

}
