define(["require","exports","tslib","rondo/v1/index"],(function(t,e,n,r){"use strict";Object.defineProperty(e,"__esModule",{value:!0}),e.Wizard=function(t){for(var e=t.steps,o=(function(){function t(){}return t.prototype.initialState=function(){return{currentStep:0,totalSteps:e.length,steps:e}},t.prototype.actionNext=function(){},t.prototype.actionPrevious=function(){},t.prototype.actionSetCurrentStep=function(t){return t},t.prototype.handleActionNext=function(t){return t.currentStep>=e.length-1||e[t.currentStep].nextAction?t:n.__assign(n.__assign({},t),{currentStep:t.currentStep+1})},t.prototype.handleActionPrevious=function(t){return t.currentStep<=0?t:n.__assign(n.__assign({},t),{currentStep:t.currentStep-1})},t.prototype.handleActionSetCurrentStep=function(t,r){return r.payload<0||r.payload>=e.length?t:n.__assign(n.__assign({},t),{currentStep:r.payload})},t.displayName="Wizard",t})(),i=function(t,e){if(e.nextAction){var i="handleAction"+e.name+"Next";o.prototype[i]=function(e,r){return e.currentStep!==t?e:n.__assign(n.__assign({},e),{currentStep:t+1})},r.handleAction(e.nextAction)(o.prototype,i,Object.getOwnPropertyDescriptor(o.prototype,i))}},p=0;p<e.length;p++)i(p,e[p]);return r.behavior(o)}}));
//# sourceMappingURL=wizard_behavior.min.js-vfl4Xd9b8.map