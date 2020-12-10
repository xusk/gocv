package contrib

//#include "fast_line_detector.h"
import "C"
import (
	"image"
	"reflect"
	"unsafe"

	"gocv.io/x/gocv"
)

type FastLineDetector struct {
	p C.FastLineDetectorPtr
}

func NewFastLineDetector() *FastLineDetector {
	return &FastLineDetector{p: C.FastLineDetector_Create()}
}

func (detector *FastLineDetector) Detect(img gocv.Mat) []image.Rectangle {
	lines := C.struct_Vecs4f{}
	C.FastLineDetector_Detect(detector.p, C.Mat(img.Ptr()), &lines)

	//to Rectangle
	cArray := lines.vecs
	length := int(lines.length)
	hdr := reflect.SliceHeader{
		Data: uintptr(unsafe.Pointer(cArray)),
		Len:  length,
		Cap:  length,
	}
	s := *(*[]C.Vec4f)(unsafe.Pointer(&hdr))
	rects := make([]image.Rectangle, length)
	for i, r := range s {
		// int(r.x1), int(r.y1), int(r.x2), int(r.y2)
		rects[i] = image.Rectangle{
			Min: image.Point{X: int(r.x1), Y: int(r.y1)},
			Max: image.Point{X: int(r.x2), Y: int(r.y2)},
		}
	}
	return rects
}
