define(["require","exports","tslib","react","classnames","comments2/components/annotation_utils"],(function(e,t,n,i,a,s){"use strict";function r(e){var t=e.rectangle,n=e.isEmphasized,r=a.default("sc-annotation-highlight-segment",{"sc-annotation-highlight-segment__emphasized":n});return i.createElement("div",{style:s.toRectangleStyle(t),className:r})}Object.defineProperty(t,"__esModule",{value:!0}),i=n.__importStar(i),a=n.__importDefault(a),t.AnnotationHighlightSegment=r,t.renderAnnotationHighlight=function(e){var t=e.key,n=e.highlight,a=e.isEmphasized;return n.map((function(e,n){return i.createElement(r,{key:t+"-"+n,rectangle:e,isEmphasized:a})}))}}));
//# sourceMappingURL=index.min.js-vflAP2hgX.map