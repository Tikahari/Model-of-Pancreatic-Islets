define(["require","exports","tslib","react","spectrum/checkbox"],(function(e,n,t,r,i){"use strict";Object.defineProperty(n,"__esModule",{value:!0});var o=(function(e){function n(){var n=null!==e&&e.apply(this,arguments)||this;return n.handler=function(e){n.props.actionFieldChange("checked"===e)},n}return t.__extends(n,e),n.prototype.render=function(){var e=this.props,n=e.fieldValue,o=t.__rest(e,["fieldValue"]);return r.createElement(i.Checkbox,t.__assign({},o,{onChange:this.handler,checked:n?"checked":"unchecked"}))},n})((r=t.__importStar(r)).Component);n.Checkbox=o;var c=(function(e){function n(){var n=null!==e&&e.apply(this,arguments)||this;return n.handler=function(e){n.props.actionFieldChange(e)},n}return t.__extends(n,e),n.prototype.render=function(){var e=this.props,n=e.fieldValue,o=t.__rest(e,["fieldValue"]);return r.createElement(i.Checkbox,t.__assign({},o,{onChange:this.handler,checked:n}))},n})(r.Component);n.CheckboxMixed=c}));
//# sourceMappingURL=checkbox.min.js-vflR4kVqu.map