define(["require","exports","modules/clean/react/growth/first_task/data/types","modules/clean/react/growth/first_task/data/store","modules/clean/react/growth/first_task/data/actions","modules/clean/react/growth/first_task/data/selectors"],(function(t,e,o,i,s,a){"use strict";Object.defineProperty(e,"__esModule",{value:!0}),e.TooltipType=o.TooltipType,e.showClinkTooltip=function(t){var e=i.getStoreForFirstTask();a.getHasClinkTooltipDisplayed(e.getState())||(t===o.TooltipType.Files&&e.dispatch(s.showClinkFilesTooltip()),t===o.TooltipType.Members&&e.dispatch(s.showClinkMembersTooltip()))},e.markClinkTooltipSeenAndHide=function(){var t=i.getStoreForFirstTask();t.dispatch(s.markClinkTooltipSeen()),t.dispatch(s.hideClinkTooltip())}}));
//# sourceMappingURL=first_task.min.js-vflQ0Eduo.map