define(["require","exports"],(function(e,t){"use strict";function n(){return{countAbove:0,countBelow:0,nearestAbove:null,nearestBelow:null}}Object.defineProperty(t,"__esModule",{value:!0}),t.createEmptyVisibilityData=n,t.calcVisibilityData=function(e,t){var n={countAbove:0,countBelow:0,nearestAbove:null,nearestBelow:null};if(!e)return n;for(var o=e.getBoundingClientRect(),r=o.top,l=o.bottom,i=0;i<t.length;i++){var u=t[i],a=u.item,c=u.ref.getBoundingClientRect();if(c.bottom<r+10)n.countAbove++,n.nearestAbove=a;else if(c.top>l-10){n.countBelow=t.length-i,n.nearestBelow=a;break}}return n}}));
//# sourceMappingURL=calc_visibility_data.min.js-vflBzzqWZ.map