package contrib

import (
	"fmt"
	"image/color"
	"testing"

	"gocv.io/x/gocv"
)

func TestNewFastLineDetector(t *testing.T) {
	detector := NewFastLineDetector()
	image := gocv.IMRead("../images/line-test.jpg", gocv.IMReadColor)
	if image.Empty() {
		t.Error("image not exist")
	}
	newImage := gocv.NewMat()
	gocv.CvtColor(image, &newImage, gocv.ColorRGBAToGray)
	rectangles := detector.Detect(newImage)
	col := color.RGBA{R: 255}
	for _, rect := range rectangles {
		fmt.Println(rect.Min, rect.Max)
		gocv.Line(&image, rect.Min, rect.Max, col, 1)
	}
	gocv.IMWrite("test.jpg", image)
}
