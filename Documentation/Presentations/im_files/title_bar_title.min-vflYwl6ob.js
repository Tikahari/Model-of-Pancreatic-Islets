define(["require","exports","tslib","react","modules/clean/react/title_bar/title_bar_logo","modules/clean/react/title_bar/title_bar_close_button"],(function(e,l,t,i,o,r){"use strict";Object.defineProperty(l,"__esModule",{value:!0}),i=t.__importDefault(i),l.TitleBarTitle=function(e){var l=e.canClose,t=e.children,n=e.closeUrl,a=e.closeTitle,s=e.file,c=e.isSigningMode,u=e.isSendForSignatureMode,d=e.onClose,_=e.overrideIcon,f=e.shouldShowIcon,b=e.sizeClass;return i.default.createElement("div",{className:"react-title-bar__title-wrap"},f&&_?_:null,f&&!_&&l?i.default.createElement(r.CloseButton,{closeTitle:a,file:s,isSigningMode:c,isSendForSignatureMode:u,closeUrl:n,onClick:d,sizeClass:b}):null,!f||_||l?null:i.default.createElement(o.Logo,null),t)}}));
//# sourceMappingURL=title_bar_title.min.js-vflcYif_u.map