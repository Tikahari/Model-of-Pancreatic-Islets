define(["require","exports","tslib","react","spectrum/datepicker","rondo-forms-spectrum/v1/fields/dateTimePicker_range","rondo-forms-spectrum/v1/fields/datepicker_util"],(function(e,t,r,o,a,n,i){"use strict";Object.defineProperty(t,"__esModule",{value:!0});var l=(function(e){function t(){return null!==e&&e.apply(this,arguments)||this}return r.__extends(t,e),t.prototype.render=function(){var e=this.props,t=e.actionFieldChange,i=e.fieldValue,l=e.fromDateLabel,d=void 0===l?"":l,f=e.toDateLabel,m=void 0===f?"":f,c=e.fromDatePlaceholder,u=void 0===c?"":c,s=e.toDatePlaceholder,D=void 0===s?"":s,p=e.renderTimeOfDay,h=void 0!==p&&p,_=r.__rest(e,["actionFieldChange","fieldValue","fromDateLabel","toDateLabel","fromDatePlaceholder","toDatePlaceholder","renderTimeOfDay"]),v=h?n.DateTimepickerRange:a.DatepickerRange;return o.createElement(v,r.__assign({},_,{fromDate:"number"==typeof i.from?new Date(i.from):i.from,toDate:"number"==typeof i.to?new Date(i.to):i.to,onRangeChanged:t,fromDateLabel:d,toDateLabel:m,fromDatePlaceholder:u,toDatePlaceholder:D}))},t})((o=r.__importStar(o)).Component);t.DatepickerRondoRange=l,t.dateRangeParseFunction=function(e){var t=e.from,r=e.to;return{from:i.dayOnlyTime(t),to:i.dayOnlyTime(r)}}}));
//# sourceMappingURL=datepicker_range.min.js-vflr9TQjX.map