package faceimage

import (
	"fmt"
	"facesdk"
	"image"
	"image/jpeg"
	"os"
)

func CutImage(src, dst string, loc facesdk.FaceLoc) error {
	in, err1 := os.Open(src)
	if err1 != nil {
		return err1
	}
	defer in.Close()

	out, err2 := os.Create(dst)
	if err2 != nil {
		return err2
	}
	defer out.Close()

	origin, fm, err := image.Decode(in)
	if err != nil {
		return err
	}

	if fm == "jpeg" {
		img := origin.(*image.YCbCr)

		x2 := loc.X + loc.Width
		y2 := loc.Y + loc.Height

		subImg := img.SubImage(image.Rect(loc.X, loc.Y, x2, y2)).(*image.YCbCr)
		return jpeg.Encode(out, subImg, &jpeg.Options{100})
	} else {
		return fmt.Errorf("not support file format:%s", fm)
	}
}
